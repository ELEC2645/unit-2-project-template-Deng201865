#include "menu.h"
#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_menu(){
    while(1){
        printf("\n\n");
        printf("Converter calculator\n--Main menu--\n");
        printf("1.buck converter\n");
        printf("2.boost converter\n");
        printf("3.buck-boost converter\n");
        printf("4.cuk converter\n");
        printf("5.basic cauculation\n");
        printf("6.exit\n");
        int main_menu_input;
        printf("\nPlease select the converter: ");
        int result = scanf("%d", &main_menu_input);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch (main_menu_input) {
            case 1: buck_menu(); break;
            case 2: boost_menu(); break;
            case 3: buck_boost_menu(); break;
            case 4: cuk_menu(); break;
            case 5: basic_menu(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }
    }
}

void basic_menu(){
    while(1){
        printf("\n\n");
        printf("--basic calculation--\n");
        printf("1.duty ratio\n");
        printf("2.output voltage\n");
        printf("3.power\n");
        printf("4.current\n");
        printf("5.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int basic_choice;
        int result = scanf("%d", &basic_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(basic_choice){
            case 1: duty_ratio(); break;
            case 2: output_voltage(); break;
            case 3: power(); break;
            case 4: current(); break;
            case 5: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }
    }
    
}

void buck_menu(){
    while(1){
        printf("\n\n");
        printf("--buck converter calculator--\n");
        printf("1.inductor\n");
        printf("2.capacitor\n");
        printf("3.CCM/DCM mode detection\n");
        printf("4.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int buck_choice;
        int result = scanf("%d", &buck_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(buck_choice){
            case 1: buck_inductor(); break;
            case 2: buck_capacitor(); break;
            case 3: buck_mode(); break;
            case 4: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }  
    }
    
}

void buck_mode(){
    while(1){
        printf("\n\n");
        printf("--buck converter mode detection--\n");
        printf("1.fix output voltage\n");
        printf("2.fix input voltage\n");
        printf("3.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int buck_mode_choice;
        int result = scanf("%d", &buck_mode_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(buck_mode_choice){
            case 1: buck_mode_cal(1); break;
            case 2: buck_mode_cal(2); break;
            case 3: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }

}

void boost_menu(){
    while(1){
        printf("\n\n");
        printf("--boost converter calculator--\n");
        printf("1.inductor\n");
        printf("2.capacitor\n");
        printf("3.CCM/DCM mode detection\n");
        printf("4.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int boost_choice;
        int result = scanf("%d", &boost_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(boost_choice){
            case 1: boost_inductor(); break;
            case 2: boost_capacitor(); break;
            case 3: boost_mode(); break;
            case 4: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }       
    }
    
}

void boost_mode(){
    while(1){
        printf("\n\n");
        printf("--boost converter mode detection--\n");
        printf("1.fix output voltage\n");
        printf("2.fix input voltage\n");
        printf("3.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int boost_mode_choice;
        int result = scanf("%d", &boost_mode_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(boost_mode_choice){
            case 1: boost_mode_cal(1); break;
            case 2: boost_mode_cal(2); break;
            case 3: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }
    
}

void buck_boost_menu(){
    while(1){
        printf("\n\n");
        printf("--buck-boost converter calculator--\n");
        printf("1.inductor\n");
        printf("2.capacitor\n");
        printf("3.CCM/DCM mode detection\n");
        printf("4.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int buck_boost_choice;
        int result = scanf("%d", &buck_boost_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(buck_boost_choice){
            case 1: buck_boost_inductor(); break;
            case 2: buck_boost_capacitor(); break;
            case 3: buck_boost_mode(); break;
            case 4: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }
    
}

void buck_boost_mode(){
    while(1){
        printf("\n\n");
        printf("--buck boost converter mode detection--\n");
        printf("1.fix output voltage\n");
        printf("2.fix input voltage\n");
        printf("3.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int buck_boost_mode_choice;
        int result = scanf("%d", &buck_boost_mode_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(buck_boost_mode_choice){
            case 1: buck_boost_mode_cal(1); break;
            case 2: buck_boost_mode_cal(2); break;
            case 3: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }
    
}

void cuk_menu(){
    while(1){
        printf("\n\n");
        printf("--cuk converter calculator--\n");
        printf("1.inductor\n");
        printf("2.capacitor\n");
        printf("3.CCM/DCM mode detection\n");
        printf("4.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int cuk_choice;
        int result = scanf("%d", &cuk_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(cuk_choice){
            case 1: cuk_inductor(); break;
            case 2: cuk_capacitor(); break;
            case 3: cuk_mode(); break;
            case 4: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }
    
}

void cuk_mode(){
    while(1){
        printf("\n\n");
        printf("--cuk converter mode detection--\n");
        printf("1.fix output voltage\n");
        printf("2.fix input voltage\n");
        printf("3.return to previous menu\n");
        printf("0.exit\n");
        printf("Please input your choice:\n");
        int cuk_mode_choice;
        int result = scanf("%d", &cuk_mode_choice);
        if(result != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch(cuk_mode_choice){
            case 1: cuk_mode_cal(1); break;
            case 2: cuk_mode_cal(2); break;
            case 3: return;
            case 0: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid selection. Please choose again.\n");break;
        }    
    }
    
}




