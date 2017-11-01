

# this module implements an unrolled linked list

# this data structure attempts to combine the strengths of a linked list 
#  - fast insert/delete from the front of a list  
#  - fast insert/delete to middle or end (with a pointer to the element)

# and the strengths of a array that supports resizing
#  - fast indexing
#  - fast insert/delete at the end of a list


# linked list
# - front insert/delete      = O(1)
# - middle/end insert/delete = O(n), O(1) with pointer
# - indexing                 = O(n)
# - wasted space             = O(n)

# array
# - front insert/delete      = O(n)
# - middle insert/delete     = O(n)
# - end insert/delete        = O(1)
# - indexing                 = O(1)
# - wasted space             = 0

# unrolled linked list
# - front insert/delete       = O(n/MAX_BLOCK_SIZE) best, O(1) worst
# - middle/end insert/delete  = O(n/MAX_BLOCK_SIZE) best, O(n) worst
# - indexing                  = O(n/MAX_BLOCK_SIZE) best, O(n) worst
# - wasted space              = O(n/MAX_BLOCK_SIZE) best, O(n) worst


# assuming the unrolled linked list stays relatively well balanced
# i.e. all blocks are half or more utilized, there are no empty blocks
# the performance should approach the best case
# using significantly less space, and
# utilizing cache much better than a standard linked list



# in the worst posible case where each block has only 1 element,
# the performance will be the same as a standard linked list,
# if not slightly worse due to overhead


# this implementation is not optimized
# at least one improvement would be to rebalance the blocks after
# removing elements

# e.g.  
# currently, remove(1, ([1,2], ([3,4,5], None)) => ([1], ([3,4,5], None))
# but remove(1, ([1,2], ([3,4,5], None)) => ([1,3], ([4,5], None))
# would be better


MAX_BLOCK_SIZE = 8



class UnrolledList(object):
    def __init__(self, lst=None):
        self.els = []
        self.next = None
        
        if lst:
            self.__from_list(lst)
            self.length = len(lst)

    
            
    # grab chunks of the list at a time
    def __from_list(self, lst):
        if len(lst) <= MAX_BLOCK_SIZE:
            self.els = lst
        else:
            
            last = self
            self.els = lst[:MAX_BLOCK_SIZE]
            
            rem_list = lst[MAX_BLOCK_SIZE:]
                        
            while len(rem_list) > 0:
                cur = UnrolledList()
                last.next = cur
                
                cur.els = rem_list[:MAX_BLOCK_SIZE]
                rem_list = rem_list[MAX_BLOCK_SIZE:]
                
                last = cur
                


    def __str__(self):
        cur = self
        no_bracket = self.els.__str__()[:-1]
        output = no_bracket
                
        cur = cur.next
        while cur:
            output += ", "
            output += cur.els.__str__()[1:-1]
            cur = cur.next
            
        output += "]"
                
        return output
    
    # print raw structure
    def __repr__(self):
        return "({}, {})".format(self.els.__repr__(),
                                 self.next.__repr__())

    def __len__(self):
        cnt = 0
        cur = self
        while cur is not None:
            cnt += len(cur.els)
            cur = cur.next
            
        return cnt

    def __iter__(self):
        
        cur_obj = self
        
        while cur_obj:
            for item in cur_obj.els:
                yield item
            cur_obj = cur_obj.next



    def __getitem__(self, idx):
        if idx < len(self.els):
            return self.els[idx]
        elif self.next:
            cur = self
            while cur and idx > len(cur.els):
                idx -= len(cur.els)
                cur = cur.next
                
            return cur.els[idx]

        else:
            raise Exception("Out-of-bounds index")

    def __setitem__(self, idx, item):
        if idx < len(self.els):
            self.els[idx] = item
            return item
        elif self.next:
            cur = self
            while cur and idx > len(cur.els):
                idx -= len(cur.els)
                cur = cur.next
            cur.els[idx] = item
            return item
        else:
            raise Exception("Out-of-bounds index")

             
    # check if this list has any elements in it
    # versus only empty blocks
    # this is a convenience method

    def has_els(self):
        cur = self
        while cur:
            if len(cur.els) > 0:
                return True
            else:
                cur = cur.next


    def append_at_end(self, el):
        if self.next == None:
            if len(self.els) == MAX_BLOCK_SIZE:
                self.next = UnrolledList([el])
                return self
            else:
                self.els.append(el)
                return self
        else:
            cur = self
            while cur:
                last = cur
                cur = cur.next
            # find end of list
            last.append_at_end(el)
            return self
            
    def pop_from_end(self):
        if self.next == None:
            # assume we have at least one element
            return self.els.pop()
        else:
            
            cur = self
            has_els = cur
            while cur:
                cur = cur.next
                if cur and len(cur.els) > 0:
                    has_els = cur
            
            # trim empty blocks
            has_els.next = None
            return has_els.pop_from_end()
                        
        
    def pop_from_front(self):
        if self.next == None:
            return self.els.pop()
        elif len(self.els) in [0,1]:
            
            if len(self.els) == 1:
                ret_val = self.pop(0)
            else:
                ret_val = None
            
            # trim empty cells from front
            cur = self
                
            while (len(cur.els) == 0):
                if cur.next:
                    cur.els = cur.next.els
                    cur.next = cur.next.next
                else:
                    break
            if not ret_val:
                ret_val = self.els.pop(0)
                
        else:
            return self.els.pop(0)
                
            
    def append_to_front(self, el):
        if len(self.els) == MAX_BLOCK_SIZE:
            head = UnrolledList([el])
            head.next = self
            return head
        else:
            self.els.insert(0, el)
            return self


    def insert(self, idx, new_el):
        # insert at the idx
        # pushing the current element to the right
        
        # here we use a simple algorithm
        # where we just push the remaining elements to their own new list
        # and place the new item at the end
        
        # ([1,2,3,4],None).insert_at(1, 13) ==> ([1,13], ([2,3,4], None))
        
        if idx < len(self.els):
            if len(self.els) == MAX_BLOCK_SIZE:
                # push remaining elements into a new link
                head_els = self.els[:idx]
                rest_els = self.els[idx:]

                head_els.append(new_el)
                self.els = head_els
                                
                
                old_next = self.next
                new_next = UnrolledList(rest_els)
                new_next.next = old_next
                self.next = new_next
                
                return new_el
                
            else:
                self.els.insert(idx, new_el)
                return new_el
                
        elif self.next:
            cur = self
            while cur and idx > len(cur.els):
                idx -= len(cur.els)
                cur = cur.next
                
            if not cur:
                raise Exception("Out-of-bounds-index")
            else:
                cur.insert(idx, new_el)
        else:
            raise Exception("Out-of-bounds index")
    
    def remove(self, idx):
        cur = self
        
        # find the correct list block
        while cur and idx > len(cur.els):
            idx -= len(cur.els)
            cur = cur.next
        
        val = cur.els[idx]
        del cur.els[idx]
        return val
    
        
    def to_list(self):
        cur = self
        res = []
        while cur is not None:
            res += cur.els
            cur = cur.next
        return res



def run_tests():
    
    
    # test converting from standard python list
    lst = [x for x in xrange(64)]
    ulst = UnrolledList(lst)
    

    assert(ulst.to_list() == lst)
    

    # test indexing
    lst[15] = 12
    ulst[15] = 12

    assert(ulst.to_list() == lst)

    a = lst[22]
    b = ulst[22]
    assert(b == a)
        
    
    # test inserting at various indices
    lst.insert(2, 13)
    ulst.insert(2, 13)
    assert(ulst.to_list() == lst)

    lst.insert(6, 22)
    ulst.insert(6, 22)
    assert(ulst.to_list() == lst)
    

    # test removing from various indices 
    lpop = lst.pop(2)
    ulpop = ulst.remove(2)
    
    assert (ulpop == lpop)
    assert (ulst.to_list() == lst)
    lpop = lst.pop(12)
    ulpop = ulst.remove(12)
    assert (ulpop == lpop)
    assert (ulst.to_list() == lst)

    
    # test append to front
    ulst.append_to_front(244)
    lst = [244] + lst
    assert(ulst.to_list() == lst)


    # test append to end
    ulst.append_at_end(123)
    lst.append(123)
    assert(ulst.to_list() == lst)

    
    # test pop from front
    ulpop = ulst.pop_from_front()
    lpop = lst.pop(0)

    assert(ulpop == lpop)
    assert(ulst.to_list() == lst)
    
    

    # test pop from end
    ulpop = ulst.pop_from_end()
    lpop = lst.pop()
    
    assert(ulpop == lpop)
    assert(ulst.to_list() == lst)

    

    # test __len__
    assert(len(ulst) == len(lst))
    
    # test iteration
    assert([x for x in ulst] == lst)

    print "Tests passed!"

    
if __name__ == '__main__':
    run_tests()
