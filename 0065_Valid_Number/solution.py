import re


def is_validate_num(s):
    input_str = s.strip()
    if "e" in input_str:
        regex_num = r"^[\+-]?((\.\d+)|(\d+\.?\d*))[Ee](\+|-)?(\d+)$"
    else:
        regex_num = "^([\+-]?[0-9]+\\d*([.]\\d*)?)$|^(-?0[.]\\d*[1-9]+)$|^0$|^([\+-]?[.]\\d+)$"
    result = re.match(regex_num, input_str)
    return result is not None
