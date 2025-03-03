void f_viajante(int** coste, int* vector, int* voptimo, int &costeoptimo, int k, int tamanyo, int &x, int ocultar){
   
    int costev, i;
    vector[0] = 0;

    while(k>=1){
        if(vector[k] != tamanyo){


            vector[k] = vector[k]+1;
            cout << "valor de k " << k << endl;
            cout << "[k-1]=" << vector[k-1] << endl;
            cout << "[k]=" << vector[k] << endl;
            cout << "coste vector: " << coste[vector[k-1]][vector[k]] << endl;
           
           if(coste[vector[k-1]][vector[k]] != 9999 &&  ciclos(vector, k) == false){
               
                // cout << "entra2?" << endl;
                if( k == tamanyo ){
                    if(coste[k][0] != 9999){
                        // cout << "entra3?" << endl;
                        costev = calcularcoste(coste, vector, tamanyo);


                        for(int p=0; p<= tamanyo; p++){
                            cout << vector[p] << " ";
                        }
                        cout << endl;
                        if(costev < costeoptimo){
                            // cout << "entra4?" << endl;
                            costeoptimo = costev;
                            for(int y=0; y<= tamanyo; y++){
                                voptimo[y]=vector[y];
                            }
                        }
                    }
                } else{
                   k = k+1;
                   vector[k]=0;
                   cout << "k: " << k << endl;
                   cout << "vector [k]: " << vector[k] << endl;
                }  
            }  
        }
        else{
            // vector[k]=0;
            k = k-1;
        }
    }
    // system("pause");
}

2// 
// Viajante de comercio T6
void f_viajante(int** coste, int* vector, int* voptimo, int &costeoptimo, int k, int tamanyo, int &x, int ocultar){
   
    int costev, i;
    vector[0] = 0;

    while(k>=1){
        if(vector[k] != tamanyo){

            vector[k] = vector[k]+1;
            /*cout << "valor de k " << k << endl;
            cout << "[k-1]=" << vector[k-1] << endl;
            cout << "[k]=" << vector[k] << endl;
            cout << "coste vector: " << coste[vector[k-1]][vector[k]] << endl;*/
           
           if(coste[vector[k-1]][vector[k]] != 999 &&  ciclos(vector, k) == false){
               
                if( k == tamanyo ){
                    if(coste[k][0] != 999){
                        costev = calcularcoste(coste, vector, tamanyo);
                        if(ocultar == 0){
                            for(int p=0; p<= tamanyo; p++){
                                cout << vector[p] << " ";
                            }
                            cout << endl;
                            cout << "COSTE del camino: " << costev << endl;
                        }
                       
                        if(costev < costeoptimo){
                           
                            costeoptimo = costev;

                            for(int y=0; y<= tamanyo; y++){
                                voptimo[y]=vector[y];
                            }
                        }
                    }
                }else{
                   k = k+1;
                   vector[k]=0;
                   /*cout << "k: " << k;
                   cout << "vector[k]: " << vector[k];*/
                }  
            }  
        }
        else{
            //vector[k]=0;
            k = k-1;
        }
    }
}


// Viajante de comercio T6
void f_viajante_RyP(int** coste, int* vector, int* voptimo, int &costeoptimo, int k, int tamanyo, int &x){
   
    int costev, i;
    vector[0] = 0;
    costeoptimo = 9999;

    while(k>=1){
        if(vector[k] != tamanyo){

            vector[k] = vector[k]+1;
            cout << "valor de k " << k << endl;
            cout << "[k-1]=" << vector[k-1] << endl;
            cout << "[k]=" << vector[k] << endl;
            cout << "coste vector: " << coste[vector[k-1]][vector[k]] << endl;
           
           if(coste[vector[k-1]][vector[k]] != 999 &&  ciclos(vector, k) == false){
               
               costev = calcularcoste(coste, vector, tamanyo);

                // los dos proximos cout son comentarios
               cout << "costeoptimo: " << costeoptimo << endl;
               cout << "costev: " << costev << endl;

                if(costeoptimo>costev){
                    cout << "entro al if" << endl;

                    if( k == tamanyo ){
                        if(coste[k][0] != 999){
                            for(int p=0; p<= tamanyo; p++){
                                cout << vector[p] << " ";
                            }

                            cout << endl;
                            cout << "COSTE del camino: " << costev << endl;
                           
                            if(costev < costeoptimo){
                               
                                costeoptimo = costev;

                                for(int y=0; y<= tamanyo; y++){
                                    voptimo[y]=vector[y];
                                }
                            }
                        }
                    }else{
                        k = k+1;
                        vector[k]=0;
                        /*cout << "k: " << k;
                        cout << "vector[k]: " << vector[k];*/
                    }
                }
            }  
        }
        else{
            //vector[k]=0;
            k = k-1;  
        }
    }
}
