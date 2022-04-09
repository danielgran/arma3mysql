#include "helper.h"
#include <string>

bool stringlib::contains(std::string &str, std::string &find) {
  return (str.find(find) != std::string::npos);
}