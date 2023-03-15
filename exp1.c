#include<math.h>
#include<stdio.h>


void func1(){

for(int i=0;i<=100;i++){
    printf("%d\n",i);
}

for(int i=0;i<=100;i++){
    double x = 1.5;
    double val = pow(x,i);
    printf("%.2f\n",val);
}

}

void func2(){
for(int i=0;i<=100;i++){
    printf("%d\n",i);
}
}

void func3(){
for(int i=0;i<=100;i++){
    int val = i*i*i;
    printf("%d\n",val);
}
}


void func4(){
for(int i=0;i<=100;i++){
    double val = i * pow(2,i);
    printf("%lf\n",val);
}
}

void func5(){
for(int i=0;i<=100;i++){
    if(i == 0)
        continue;
    double val = log2(i);
    printf("%lf\n",val);
}

}


void func6(){
for(int i=0;i<=100;i++){
    if(i == 0)
        continue;
    double val = pow(log(i),log(i));
    printf("%lf\n",val);
}
}


void func7(){
for(int i=0;i<=100;i++){
    if(i == 0)
        continue;
    double val = i * log2(i);
    printf("%lf\n", val);
}
}


void func8(){
for(int i=0;i<=100;i++){
    printf("%lf\n", exp(i));
}
}


void func9(){
    for(int i=0;i<=100;i++){
    if(i == 0)
        continue;
    double val = log(i);
    printf("%lf\n", val);
}
}


void func10(){
for(int i=0;i<=100;i++){
    if(i == 0)
        continue;
    double val = i * log(i);
    printf("%lf\n", val);
}
}

void func11(){
    double val = 1;
    for(int i=1;i<20;i++){
        val *= i;
        printf("%lf\n", val);
    }
}

int main(){
func11();
return 0;
}
