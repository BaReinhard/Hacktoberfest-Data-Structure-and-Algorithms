math.randomseed(os.time())

local function inorder(t)
    for i = 1, #t - 1 do
        if t[i] > t[i + 1] then
            return false
        end
    end
    return true
end

local function shuffle(t)
    local tLen = #t
    for i = 1, tLen do
        local index1, index2 = math.random(1, tLen), math.random(1, tLen)
        t[index1], t[index2] = t[index2], t[index1]
    end
end

local function bogosort(t)
    while not inorder(t) do
        shuffle(t)
    end
    return t
end

local args = { ... }
for i=1,#args do
    args[i] = tonumber(args[i])
end
print(("Input: {%s}"):format(table.concat(args, ", ")))
print(("Sorted: {%s}"):format(table.concat(bogosort(args), ", ")))