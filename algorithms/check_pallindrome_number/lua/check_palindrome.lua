local function isPalindrome(s)
    s = tostring(s)
    return s:sub(1, math.floor(#s / 2 + .5)) == s:sub(math.ceil(#s / 2 + .5)):reverse()
end
print(isPalindrome(table.concat({ ... }, "")))