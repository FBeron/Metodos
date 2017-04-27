#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

#define DX 1.0
#define DT 0.1
#define L 102
#define A 1
#define B 101
#define V  0.0001

void imprimir(float data[L][L]);
void guardar_placa(float data[L][L], float t, int caso, int condicion)
void init_temp(float data[L][L]);
void solve_dt(float data[L][L], float data_o[L][L], float alpha, int caso, int condicion);
void copy_1to2(float data_1[L][L], float data_2[L][L]);
float t_prom(float data[L][L]);

int main(){
  float alpha = V*DT/pow(DX,2);
  float temp[L][L];
  float temp_old[L][L];
  int caso;
  int condicion;
  bool t0;
  int t;

  for(caso=1; caso<=2;caso++){
    for(condicion=1; condicion<=3; condicion++){
        init_temp(temp_old);
        t = DT;
        solve_dt(temp, alpha, caso, concicion)
        while(t<=2500.0){
	        solve_dt(temp, temp_old, alpha, caso, condicion, t0);
	        if(t0){
	            t0 = false;
	        }
        }
    }
  }
  caso = 1;
  condicion = 1;
  return 0;
}

void imprimir(float data[L][L]){
  int i,j;
  for(i=A; i<B;i++){
    for(j=A; j<B;j++){
      printf("%f\t", data[i][j]);
    }
    printf("\n");
  }
}

void guardar_placa(float data[L][L], float t, int caso, int condicion){
  FILE *in;
  char filename[100]="new_data.dat";

  in = fopen(filename,"w");
  imprimir(data[L][L]);
  fclose(in);
}

void guardat_tpromedio(float Te, float t, int caso, int condicion){
  FILE *in2;
  char filename[100]="new_data2.dat";

  in2 = fopen(filename,"a");
  fprintf(in2, "%f\t%f\n", t, Te);
  fclose(in2);
}

void copy(float data_1[L][L], float data_2[L][L]){
  int i,j;
  for(i=A;i<B;i++){
    for(j=A;j<B;j++){
      data_1[i][j] = data_2[i][j];
    }
  }
}

void init_temp(float data[L][L]){
  int i, j;
  for(i=0; i<L; i++){
    for(j=0; j<L; j++){
      if((i>=A+20) && (i<A+40) && (j>=A+45) && (j<A+55)){
	data[i][j] = 100.0;
      }else{
	data[i][j] = 50.0;
      }
    }
  }
}

void solve_dt(float data[L][L], float alpha, int caso, int condicion){
    float data_new[L][L];
    
    condicion(data, condicion);
    
    int i,j;
    for(i=A; i<B;i++){
        for(j=A; j<B;j++){
            data_new[i][j] = data[i][j] +  alpha*(data[i+1][j] + data[i-1][j] + data[i][j+1] + data[i][j-1]- 4*data[i][j]);
        }
    }
    copy(data, data_new);
}

float t_prom(float data[L][L]){
  int i,j;
  float sum, num, avg;

  sum = 0.0;
  num = 0.0;

  for(i=A; i<B;i++){
    for(j=A; j<B;j++){
      sum = sum + data[i][j];
      num = num + 1.0;
    }
  }

  avg = sum/num;
  return avg;
}

void condiciones(float data[L][L], int condicion){
    int i;
    if (condicion ==1){
        for(i=A;i<B;i++){
            data[i][0] = data[i][1];
            data[i][B] = data[i][B-1];
            data[0][i] = data[1][i];
            data[B][i] = data[B-1][i];
        }
    }else if(condicion ==2){
        for(i=A;i<B;i++){
            data[i][0] = data[i][B-1];
            data[i][B] = data[i][1];
            data[0][i] = data[B-1][i];
            data[B][i] = data[1][i];
        }
    }else{
        for(i=A;i<B;i++){
            data[i][0] = 50.0;
            data[i][B] = 50.0;
            data[0][i] = 50.0;
            data[B][i] = 50.0;
        }
    }
}