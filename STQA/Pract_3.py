def is_leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        return True
    else:
        return False

def is_valid_date(day, month, year):
    if year < 1:
        return False
    if month < 1 or month > 12:
        return False
    if day < 1:
        return False
    
    if month in {1, 3, 5, 7, 8, 10, 12}:
        if day > 31:
            return False
    elif month in {4, 6, 9, 11}:
        if day > 30:
            return False
    elif month == 2:
        if is_leap_year(year):
            if day > 29:
                return False
        else:
            if day > 28:
                return False
    
    return True