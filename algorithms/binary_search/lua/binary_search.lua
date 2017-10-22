--Python implementation of binary search ported to lua

local function b_search(haystack, needle, first, last)
    first, last = first or 1, last or #haystack
    local pivot = math.floor((start + last) / 2)
    if first > last then
        return -1
    elseif needle == haystack[pivot] then
        return pivot
    elseif needle > haystack[pivot] then
        return b_search(haystack, needle, pivot + 1, last)
    elseif needle < haystack[pivot] then
        return b_search(haystack, needle, start, pivot - 1)
    end
end

local args = { ... }
local target = ... --First argument is the needle, the rest are the haystack.
local tbl = {}
for i = 2, #args do
    tbl[i - 1] = args[i]
end
print('Pos: ')
print(b_search(tbl, target, 1, #tbl))
