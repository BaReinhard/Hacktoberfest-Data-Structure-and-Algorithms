__author__ = "Matteo Veraldi"
__email__ = "mattveraldi@gmail.com"
__github__ = "mattveraldi"

def gnome_sort(lis):
    pos = 0
    while(pos < len(lis)):
        if(pos == 0 or lis[pos] >= lis[pos-1]):
            pos += 1
        else:
            lis[pos], lis[pos-1] = lis[pos-1], lis[pos]
            pos -= 1
    return lis

def test():
    test_list = [119, 18, 51, 11, 9, 8.5]
    expected = [8.5, 9, 11, 18, 51, 119]
    print("###GNOME SORT by Matteo Veraldi (github.com/mattveraldi)###")
    assert gnome_sort(test_list) == expected, "test failed."
    print("test ok.")
