#include "validation.h"

int validateStudentID(char id[]){
    for (int i = 0; id[i] != '\0'; i++){
        if(!((id[i] >= 'A' && id[i] <= 'Z') ||
            (id[i] >= 'a' && id[i] <= 'z')||
            (id[i] >= '0' && id[i] <= '9'))){
                return 0;
            }
    }
    return 1;
    
}
int validateName(char name[]){
    for (int i = 0; name[i] != '\0'; i++){
        if(!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))){
            return 0;
        }
    }
    return 1;
    
}
int validateMinor(float minor){
    return (minor >= 0 && minor <= 40);
}
int validateMajor(float major){
    return (major >= 0 && major <= 60);
}