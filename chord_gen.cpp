#include <stdlib.h>
#include <Math.h>
#include "..\ChordGen\ChordGen.h"
#include "m_pd.h"
#include "..\ChordGen\Scale.h"
#include "..\ChordGen\ChordSequence.h"
#include <vector>
#include <string>
#include <string.h>

using namespace std;

static t_class *chord_gen_class;

typedef struct _chord_gen {
    t_object x_obj;
    ChordGen* cg;
    t_outlet *out1;
} t_chord_gen;

void toFloatArray(int argc, t_atom* argv, float array[]) {
    int i;
    for (i = 0; i < argc; i++) {
        array[i] = atom_getfloat(argv + i);
    }
}

vector<float> toVector(int argc, t_atom* argv) {
    vector<float> v;
    for (int i = 0; i < argc; i++) {
        v.push_back(atom_getfloat(argv + i));
    }
    return v;
}

void fromFloatArray(int argc, float* array, t_atom* argv) {
    int i;
    for (i = 0; i < argc; i++) {
        SETFLOAT(argv + i, *(array + i));
    }
}

void chord_gen_generate(t_chord_gen *x,
        t_floatarg f1) {
    x->cg->generate();
}

void chord_gen_get(t_chord_gen *x, t_floatarg f1) {
    int index = (int) f1;

    vector<int> chord = x->cg->get(index);
    t_atom output[chord.size()];
    for (int i = 0; i < chord.size(); i++)
        SETFLOAT(&(output[i]), (float) chord[i]);

    outlet_list(x->out1, &s_list, chord.size(), output);
}

void root(t_chord_gen *x, const t_symbol *sss, int argc, t_atom *argv) {
    if (argc > 0) {
        int r = atom_getint(argv);
        if (r >= 0)
            x->cg->setRoot(r % 12);
    } else {
        x->cg->setRoot();
    }
}

void setSequenceLength(t_chord_gen *x, const t_symbol *sss, int argc, t_atom *argv) {
    if (argc > 0) {
        int r = atom_getint(argv);
        if (r >= 0)
            x->cg->setSequenceLength(r);
    } else {
        x->cg->setSequenceLength();
    }
}

void density(t_chord_gen *x, const t_symbol *sss, int argc, t_atom *argv) {
    if (argc > 0) {
        float r = atom_getfloat(argv);
        if (r >= 0)
            x->cg->setDensity(r);
    } else {
        x->cg->setDensity();
    }
}

void setScaleType(t_chord_gen *x, const t_symbol *sss, int argc, t_atom *argv) {
    if (argc > 0) {
        char* s = (char*) calloc(100, sizeof (char));
        
        post(s);
        atom_string(argv, s, 100);
        if (strcmp(s,"major") == 0) {
            x->cg->setScaleType(Scale::Major);
        } else if (strcmp(s,"naturalminor") == 0) {
            x->cg->setScaleType(Scale::NaturalMinor);
        } else if (strcmp(s,"harmonicminor") == 0) {
            x->cg->setScaleType(Scale::HarmonicMinor);
        } else if (strcmp(s,"melodicminor") == 0) {
            x->cg->setScaleType(Scale::MelodicMinor);
        }
    } else {
        x->cg->setScaleType();
    }
}

void store(t_chord_gen *x, float f) {
    if (f >= 0 && f < 32)
        x->cg->store((int) f);
}

void recall(t_chord_gen *x, float f) {
    if (f >= 0 && f < 32)
        x->cg->recall((int) f);
}

void print(t_chord_gen *x, const t_symbol *sss, int argc, t_atom *argv) {
    post("\n===== ChordGen =====");
    post("root = %d, set = %s", x->cg->getRoot(), x->cg->isRootSet() ? "true" : "false");
    post("sequencelength = %d, set = %s", x->cg->getSequenceLength(), x->cg->isSequenceLengthSet() ? "true" : "false");
    post("scaletype = %s, set = %s", Scale::toString(x->cg->getScaleType()), x->cg->isScaleTypeSet() ? "true" : "false");
    post("density = %f, set = %s", x->cg->getDensity(), x->cg->isDensitySet() ? "true" : "false");
    
    post("");
    
    ChordSequence* seq = x->cg->getChordSequence();
    for(int i = 0; i < x->cg->getSequenceLength(); i++){
        post("chord %2d: %s", i, seq->getChord(i).toString().c_str());
    }
}

void *chord_gen_new(t_symbol *s, int argc, t_atom *argv) {
    t_chord_gen *x = (t_chord_gen *) pd_new(
            chord_gen_class);

    x->cg = new ChordGen();

    x->out1 = outlet_new(&x->x_obj, &s_list);

    return (void *) x;
}

extern "C"
void chord_gen_setup(void) {

    chord_gen_class = class_new(gensym("chord_gen"),
            (t_newmethod) chord_gen_new, 0,
            sizeof (t_chord_gen), CLASS_DEFAULT, A_GIMME, 0);

    class_addfloat(chord_gen_class, (t_method) chord_gen_get);

    class_addmethod(chord_gen_class,
            (t_method) chord_gen_generate,
            gensym("generate"), A_DEFFLOAT, 0);

    class_addmethod(chord_gen_class,
            (t_method) setSequenceLength,
            gensym("sequencelength"), A_GIMME, 0);

    class_addmethod(chord_gen_class,
            (t_method) root,
            gensym("root"), A_GIMME, 0);

    class_addmethod(chord_gen_class,
            (t_method) density,
            gensym("density"), A_GIMME, 0);

    class_addmethod(chord_gen_class,
            (t_method) setScaleType,
            gensym("scaletype"), A_GIMME, 0);

    class_addmethod(chord_gen_class,
            (t_method) store,
            gensym("store"), A_DEFFLOAT, 0);

    class_addmethod(chord_gen_class,
            (t_method) recall,
            gensym("recall"), A_DEFFLOAT, 0);

    class_addmethod(chord_gen_class,
            (t_method) print,
            gensym("print"), A_GIMME, 0);


    class_sethelpsymbol(chord_gen_class,
            gensym("chord_gen-help"));
}
