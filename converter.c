#include "converter.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_msg(){
    printf("Invalid input, please check your input\n");
}

void flush_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
}

int number_detection(const char *s){
    if (s == NULL || *s == '\0'){
        return 0;
    }
    const char *p = s;
    if (*p == '+' || *p == '-'){
        p++;
    }
    int has_dot = 0;
    int has_number = 0;
    while(*p != '\0'){
        if (*p >= '0' && *p <= '9'){
            has_number = 1;
        }else if(*p == '.'){
            if(has_dot == 1){
                return 0;
            }
            has_dot = 1;
        }else{
            return 0;
        }
        p++;
    }
    return has_number;
}

int ask_number(double *out_number){
    if(out_number == NULL) return -1;
    char line[100];
    if (!fgets(line, sizeof line, stdin)) {
        flush_input_buffer();
        return -1;
    }
    if (strchr(line, '\n') == NULL) {
        flush_input_buffer();
    }
    line[strcspn(line, "\n")] = '\0';
    if (!number_detection(line)) {
        return -2;
    }
    *out_number = atof(line);
    return 0;
}

void duty_ratio(){
    flush_input_buffer();
    double Vin,Vout;
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        printf("The duty ratio is %.6f\n",K);
    }else{
        printf("The input voltage should greater than 0, please check your input\n");
    }
    
}

void output_voltage(){
    double Vin,K;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the duty ratio K: ");
    while(ask_number(&K) != 0){
        error_msg();
    }
    double Vout = K * Vin;
    printf("The output voltage is %.6f V\n",Vout);
    
}


void power(){
    double Vin,Vout,Iin,Iout;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the input current Iin: ");
    while(ask_number(&Iin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output current Iout: ");
    while(ask_number(&Iout) != 0){
        error_msg();
    }
    double Pin = Vin * Iin;
    double Pout = Vout * Iout;
    if(Pin <= 0){
        printf("The input power is 0 or negative, which is invalid\n");
        return;
    }
    if(Pout > Pin){
        printf("The output power is %.6f W, and the input power is %.6f W, Pout > Pin, which is impossible, please check your input.\n",Pout,Pin);
        return;
    }
    double Ploss = Pin - Pout;
    double eff = Pout / Pin;
    printf("The input power is :%.6f W\n",Pin);
    printf("The output power is :%.6f W\n",Pout);
    printf("The power loss is :%.6f W\n",Ploss);
    if(eff > 1 || eff < 0){
        printf("The efficiency is %6f, which is impossible, please check your input\n",eff);
    }else{
        printf("The efficiency is :%.6f\n",eff);
    }
    if(Ploss > 0){
        printf("The quantity is %.6f\n",Pout / Ploss);
        
    }else{
        printf("Power loss cannot equal or less than 0, please check your input\n");
    }
}

void current(){
    double Iout,dIl;
    flush_input_buffer();
    printf("\nPlease enter the output current Iout: ");
    while(ask_number(&Iout) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple dIL: ");
    while(ask_number(&dIl) != 0){
        error_msg();
    }
    double I_avg = Iout;
    double I_peak = (Iout + dIl) / 2;
    double I_valley = (Iout - dIl) / 2;
    printf("The average current in inductor is %.6f A\n",I_avg);
    printf("The current peak in inductor is %.6f A\n",I_peak);
    printf("The current valley in inductor is %.6f A\n",I_valley);
    
}

void buck_inductor(){
    double Vin,Vout,f,dIl;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple dIL: ");
    while(ask_number(&dIl) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(dIl != 0 && f != 0){
            double L = ((Vin - Vout)*K) / (dIl * f);
            printf("The required inductance is %.6f H\n",L);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void buck_capacitor(){
    double Vin,Vout,f,dVo,L;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage ripple dVout: ");
    while(ask_number(&dVo) != 0){
        error_msg();
    }
    printf("\nPlease enter the inductance L: ");
    while(ask_number(&L) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(f != 0 && dVo != 0 && L != 0){
            double C = ((Vin - Vout)/(8 * f * f * dVo * L)) * K;
            printf("The required capacitor is %.6f F\n",C);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void buck_mode_cal(int mode){
    double Vin,Vout,K,Ts,L,Iout;
    flush_input_buffer();
    if(mode == 1){
        printf("\nPlease enter the output voltage Vout: ");
        while(ask_number(&Vout) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = ((Vout * Ts) * (1 - K)) / (2 * L);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
        
    }
    if(mode == 2){
        printf("\nPlease enter the input voltage Vin: ");
        while(ask_number(&Vin) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = ((Vin * Ts) * (1 - K)) / (2 * L);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
    }
}

void boost_inductor(){
    double Vin,Vout,f,dIl;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple dIL: ");
    while(ask_number(&dIl) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(dIl != 0 && f != 0){
            double L = (Vin * K) / (f * dIl);
            printf("The required inductance is %.6f H\n",L);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void boost_capacitor(){
    double Vin,Vout,f,dVo,R;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage ripple dVo: ");
    while(ask_number(&dVo) != 0){
        error_msg();
    }
    printf("\nPlease enter the resistance R: ");
    while(ask_number(&R) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(f != 0 && dVo != 0 && R != 0){
            double C = (Vout * K)/(dVo * R * f);
            printf("The required capacitor is %.6f F\n",C);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void boost_mode_cal(int mode){
    double Vin,Vout,K,Ts,L,Iout;
    flush_input_buffer();
    if(mode == 1){
        printf("\nPlease enter the output voltage Vout: ");
        while(ask_number(&Vout) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = (Ts * Vout * K * (1 - K)) / (2 * L);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
        
    }
    if(mode == 2){
        printf("\nPlease enter the input voltage Vin: ");
        while(ask_number(&Vin) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = (K * Ts * Vin) / (2 * L);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }  
        }else{
            error_msg();
        }
    }
}

void buck_boost_inductor(){
    double Vin,Vout,f,dIl;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple dIL: ");
    while(ask_number(&dIl) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(dIl != 0 && f != 0){
            double L = (Vin * K) / (f * dIl);
            printf("The required inductance is %.6f H\n",L);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void buck_boost_capacitor(){
    double Vin,Vout,f,dVo,R;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage ripple dVo: ");
    while(ask_number(&dVo) != 0){
        error_msg();
    }
    printf("\nPlease enter the resistance R: ");
    while(ask_number(&R) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(f != 0 && dVo != 0 && R != 0){
            double C = (Vout * K)/(dVo * R * f);
            printf("The required capacitor is %.6f F\n",C);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void buck_boost_mode_cal(int mode){
    double Vin,Vout,K,Ts,L,Iout;
    flush_input_buffer();
    if(mode == 1){
        printf("\nPlease enter the output voltage Vout: ");
        while(ask_number(&Vout) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = (Ts * Vout * (1 - K))/(2 * L);
            printf("The Boundary current is %.6f A",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
        
    }
    if(mode == 2){
        printf("\nPlease enter the input voltage Vin: ");
        while(ask_number(&Vin) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the inductance L: ");
        while(ask_number(&L) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L != 0){
            double IB = (K*Ts*Vin) / (2 * L);
            printf("The Boundary current is %.6f A",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
        }else{
            error_msg();
        }
    }
}

void cuk_inductor(){
    double Vin,Vout,f,dIl1,dIl2;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch fs: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple in the input inductor L1: ");
    while(ask_number(&dIl1) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple in the output inductor L2: ");
    while(ask_number(&dIl2) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        if(dIl1 != 0 && dIl2 != 0 && f != 0){
            double L1 = (Vin * K) / (f * dIl1);
            double L2 = (Vin * K) / (f * dIl2);
            printf("\nThe required input inductance L1 is %.6f H, and the required output inductance L2 is %.6f H\n",L1,L2);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void cuk_capacitor(){
    double Vin,Vout,f,dVo,dVcn,dIl2,L2;
    flush_input_buffer();
    printf("\nPlease enter the input voltage Vin: ");
    while(ask_number(&Vin) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage Vout: ");
    while(ask_number(&Vout) != 0){
        error_msg();
    }
    printf("\nPlease enter the frequency of switch f: ");
    while(ask_number(&f) != 0){
        error_msg();
    }
    printf("\nPlease enter the output voltage ripple dVout: ");
    while(ask_number(&dVo) != 0){
        error_msg();
    }
    printf("\nPlease enter the voltage ripple in the capacitor Cn: ");
    while(ask_number(&dVcn) != 0){
        error_msg();
    }
    printf("\nPlease enter the current ripple in the output inductor dIL2: ");
    while(ask_number(&dIl2) != 0){
        error_msg();
    }
    printf("\nPlease enter the inductance L2: ");
    while(ask_number(&L2) != 0){
        error_msg();
    }
    if(Vin > 0){
        double K = Vout / Vin;
        double Ts = 1 / f;
        if(f != 0 && dVo != 0 && dVcn != 0 && L2 != 0){
            double Co = (Vin * K)/(8 * f * f * dVo * L2);
            double Cn = (dIl2 * K * Ts)/(dVcn);
            printf("\nThe required output capacitor Co is %.6f F, and the capacitor Cn is %.6f F\n",Co,Cn);
            
        }else{
            error_msg();
        }
    }else{
        printf("The input voltage cannot less than 0, please check your input\n");
    }
}

void cuk_mode_cal(int mode){
    double Vin,Vout,K,Ts,L1,L2,Iout;
    flush_input_buffer();
    if(mode == 1){
        printf("\nPlease enter the output voltage Vout: ");
        while(ask_number(&Vout) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the input inductance L1: ");
        while(ask_number(&L1) != 0){
            error_msg();
        }
        printf("\nPlease enter the output inductance L2: ");
        while(ask_number(&L2) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L1 + L2 != 0){
            double Lp = (L1 * L2)/(L1 + L2);
            double IB = (Ts * Vout * (1 - K) * (1 - K))/(2 * Lp);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
        
    }
    if(mode == 2){
        printf("\nPlease enter the input voltage Vin: ");
        while(ask_number(&Vin) != 0){
            error_msg();
        }
        printf("\nPlease enter the switch period Ts: ");
        while(ask_number(&Ts) != 0){
            error_msg();
        }
        printf("\nPlease enter the duty ratio K: ");
        while(ask_number(&K) != 0){
            error_msg();
        }
        printf("\nPlease enter the input inductance L1: ");
        while(ask_number(&L1) != 0){
            error_msg();
        }
        printf("\nPlease enter the output inductance L2: ");
        while(ask_number(&L2) != 0){
            error_msg();
        }
        printf("\nPlease enter the output current Iout: ");
        while(ask_number(&Iout) != 0){
            error_msg();
        }
        if(L1 + L2 != 0){
            double Lp = (L1 * L2)/(L1 + L2);
            double IB = (Ts * Vin * K * (1 - K))/(2 * Lp);
            printf("The Boundary current is %.6f A\n",IB);
            if (Iout > IB){
                printf("The converter is working under CCM(Continuous Conduction Mode)\n");
            }else{
                printf("The converter is working under DCM(Discontinuous Conduction Mode)\n");
            }
            
        }else{
            error_msg();
        }
    }
}




