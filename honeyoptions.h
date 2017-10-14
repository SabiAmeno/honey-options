#ifndef HONEYOPTIONS_H
#define HONEYOPTIONS_H

#include <string>
#include <map>
#include <vector>

//needn't add any value
//if you add,this value will be ignored
#define arg_null 0

//must add option value
//it will error if no value added
#define arg_required 1

//option value is optional
#define arg_optional  2

//option
struct option {
    std::string opt_name;  //long name
    std::string sim_name;  //simple name
    int opt; //argument option arg_null/arg_required/arg_optional
};

class HoneyOptions
{
public:
    HoneyOptions();

    inline void setopts(option* opts)
    {
        this->opts = opts;
    }

    bool process(int argc, char** argv);

    const std::string operator[](const std::string& opt);

    inline bool hasopt(const std::string& nopt)
    {
        return opt_res.find(nopt) != opt_res.end();
    }

private:
    //get option by opt name
    option getopt(const std::string& opt);
private:
	option* opts;

    typedef std::map<std::string, std::string> opt_result;
    opt_result opt_res;
};

#endif // HONEYOPTIONS_H
