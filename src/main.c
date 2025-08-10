#include <stdio.h>
#include "websocket.h"
#include <pthread.h>
void* input_handle(void* arg) {
    while (1) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        // Procesar la entrada del usuario
    }
}

int main(){
    pthread_t input_thread_id, ws_thread;
    //creamos los threads
    pthread_create(&input_thread_id, NULL, input_handle, NULL);
    pthread_create(&ws_thread, NULL, mainWebsocket, NULL);
    
    //esperamos a que terminen
    pthread_join(input_thread_id, NULL);
    pthread_join(ws_thread, NULL);


    return 0;

}
