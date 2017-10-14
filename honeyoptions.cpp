#include "honeyoptions.h"

HoneyOptions::HoneyOptions()
{
}

bool HoneyOptions::process(int argc, char **argv)
{
    bool all_opts_valid = true;
    for(int i = 1;i < argc;) {
        std::string opt = argv[i];
        char first_c = opt[0];
        if(first_c == '-') {
            option validopt = getopt(opt);
            switch(validopt.opt)
            {
            case arg_null: {
                opt_res[validopt.opt_name] = "";
                opt_res[validopt.sim_name] = "";
                i++;
                break;
            }
            case arg_required: {
                if(i + 1 == argc || argv[i + 1][0] == '-')
                    all_opts_valid = false;
                else {
                    std::string next_opt = argv[i + 1];
                    opt_res[validopt.opt_name] = next_opt;
                    opt_res[validopt.sim_name] = next_opt;
                    i += 2;
                }
                break;
            }
            case arg_optional: {
                if(i + 1 == argc || argv[i + 1][0] == '-') {
                    opt_res[validopt.opt_name] = "";
                    opt_res[validopt.sim_name] = "";
                    i++;
                    break;
                }
                std::string next_opt = argv[i + 1];
                opt_res[validopt.opt_name] = next_opt;
                opt_res[validopt.sim_name] = next_opt;
                i += 2;
                break;
            }
            default:i++;break;
            }
        } else
            i++;
        if(!all_opts_valid)
            return false;
    }

    return true;
}

const std::string HoneyOptions::operator[](const std::string& opt)
{
    auto fid = opt_res.find(opt);
    if(fid == opt_res.end())
        return "";
    return fid->second;
}

option HoneyOptions::getopt(const std::string &opt)
{
    option valid_opt;

	int i = 0;
	option o = opts[i];
	while (!o.opt_name.empty()) {
		if (("--" + o.opt_name) == opt || ("-" + o.sim_name) == opt) {
			valid_opt = o;
			break;
		}
		o = opts[++i];
	}

    return valid_opt;
}

