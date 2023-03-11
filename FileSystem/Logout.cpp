
#include "../Utils/AdminStructure.h"
#include "../Utils/Functions.h"
#include "Logout.h"
#include "../Utils/Variables.h"





Logout::Logout() {
    executeLogout();
}

void Logout::executeLogout() {
    if (!_user_logged.logged_in)
        return coutError("Error: No existe ningún usuario logeado.", NULL);

    User user;
    _user_logged = user;
}


