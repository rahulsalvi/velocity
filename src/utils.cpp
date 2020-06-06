#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <pwd.h>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

#include "utils.h"

using std::fgets;
using std::FILE;
using std::ifstream;
using std::string;
using std::stringstream;
using std::system;

namespace velocity::utils {
    string get_cwd() {
        char buf[CWD_BUF_SIZE];
        if (!getcwd(buf, CWD_BUF_SIZE)) { return ""; }
        return string(buf);
    }

    string get_homedir() {
        const char* homedir;
        if (!(homedir = getenv("HOME"))) {
            struct passwd* pw = getpwuid(getuid());
            if (pw) { homedir = pw->pw_dir; }
        }
        if (!homedir) { return ""; }
        return string(homedir);
    }

    bool path_exists(string path) {
        struct stat stat_buf;
        return (stat(path.c_str(), &stat_buf) == 0);
    }

    string file_contents(string file) {
        ifstream in_file;
        in_file.open(file);

        stringstream out_stream;
        out_stream << in_file.rdbuf();

        return out_stream.str();
    }

    int utf8_strlen(const string& str) {
        int         len = 0;
        const char* s   = str.c_str();
        while (*s) { len += (*s++ & 0xC0) != 0x80; }
        return len;
    }

    string exec_stdout(const char* cmd) {
        string result = "";
        FILE*  pipe   = popen(cmd, "r");
        if (!pipe) { return ""; }
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) { result += buffer; }
        pclose(pipe);
        return result;
    }

    int exec_exit_code(const char* cmd) { return WEXITSTATUS(system(cmd)); }

} // namespace velocity::utils
