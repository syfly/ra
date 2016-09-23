typedef struct hmm_sys_t
{
    obj;
    states;
    start_p;
    trans_p;
    emit_p;
} hmm_sys_t;

void Baum_Welch()
{

}

void Forward_Backward ()
{

}

void Viterbi()
{
    
}

void va_do()
{
    hmm_sys_t
    states = ('Rainy', 'Sunny')
    observations = ('walk', 'shop', 'clean')
    start_probability = {'Rainy': 0.6, 'Sunny': 0.4}
    transition_probability = { 'Rainy' : {'Rainy': 0.7, 'Sunny': 0.3}, 'Sunny' : {'Rainy': 0.4, 'Sunny': 0.6},
    emission_probability = { 'Rainy' : {'walk': 0.1, 'shop': 0.4, 'clean': 0.5}, 'Sunny' : {'walk': 0.6, 'shop': 0.3, 'clean': 0.1},
    }
}