#include <iostream>
#include <iapi.h>
#include <ierrors.h>

void *minst = nullptr;

int main() {
    std::cout << "Hello, World!" << std::endl;

    // gs -dNOPAUSE -sDEVICE=png16m -r200  -sOutputFile=document-%02d.png document.pdf -dBATCH
    int code, code1;
    const char * gsargv[8];
    int gsargc = 8;
    gsargv[0] = "";
    gsargv[1] = "-dNOPAUSE";
    gsargv[2] = "-dBATCH";
    gsargv[3] = "-dSAFER";
    gsargv[4] = "-sDEVICE=png16m";
    gsargv[5] = "-r200";
    gsargv[6] = "-sOutputFile=../document-%02d.png";
    gsargv[7] = "../input.pdf";

    code = gsapi_new_instance(&minst, NULL);
    if (code < 0)
        return 1;
    code = gsapi_set_arg_encoding(minst, GS_ARG_ENCODING_UTF8);
    if (code == 0)
        code = gsapi_init_with_args(minst, gsargc, const_cast<char **>(gsargv));
    code1 = gsapi_exit(minst);
    if ((code == 0) || (code == gs_error_Quit))
        code = code1;

    gsapi_delete_instance(minst);

    if ((code == 0) || (code == gs_error_Quit))
        return 0;
    return 1;

}
