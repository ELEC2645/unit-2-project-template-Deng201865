#ifndef CONVERTER_H
#define CONVERTER_H

void error_msg(void);
int number_detection(const char *s);
void flush_input_buffer(void);
int ask_number(double *out_number);

void duty_ratio(void);
void output_voltage(void);
void power(void);
void current(void);

void buck_inductor(void);
void buck_capacitor(void);
void buck_mode(void);
void buck_mode_cal(int mode);

void boost_inductor(void);
void boost_capacitor(void);
void boost_mode(void);
void boost_mode_cal(int mode);


void buck_boost_inductor(void);
void buck_boost_capacitor(void);
void buck_boost_mode(void);
void buck_boost_mode_cal(int mode);

void cuk_inductor(void);
void cuk_capacitor(void);
void cuk_mode(void);
void cuk_mode_cal(int mode);



#endif