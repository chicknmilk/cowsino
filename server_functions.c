#include "server_functions.h"
#include "global.h"
#include "account_functions.h"
#include "pipe_networking.h"

void exit_function(int to_client, char buffer[], struct account *account) {

    // includes another parameter of the account struct from the file
    // find the account in the file and update its balance!
    // STILL TO FINISH

    write(to_client, buffer, BUFFER_SIZE);
    printf("sent exit to client\n");
}

void help_function(int to_client, int logged_in) {

    char * buffer = malloc(BUFFER_SIZE);

    if (logged_in == 1) {
      // the user is logged in, show game commands
      buffer = "Commands:\nplay flip <bet amount> <bet guess>\nplay dice <bet amount> <num dice> <bet guess>\nplay wheel <amount spun>\nbalance\nexit\n";
    } else {
      // the user is not logged in, show login commands
      buffer = "Commands:\nlogin <username> <password>\ncreate <username> <password>\nexit\n";
    }
    write(to_client, buffer, BUFFER_SIZE);
    printf("sent help to client\n");
}

void balance_function(int to_client, struct account *account) {
      
    char * buffer = malloc(BUFFER_SIZE);
    sprintf(buffer, "Your balance is: %d\n", account -> balance);
    write(to_client, buffer, BUFFER_SIZE);
    printf("sent balance to client\n");
}