var LinkedList = function(e){

   var that = {}, first, last;

   that.push = function(value){
      var node = new Node(value);
      if(first == null){
         first = last = node;
      }else{
         last.next = node;
         last = node;
      }
   };

   that.pop = function(){
      var value = first;
      first = first.next;
      return value;
   };

   that.remove = function(index) {
      var i = 0;
      var current = first, previous;
      if(index === 0){
          //handle special case - first node
          first = current.next;
      }else{
          while(i++ < index){
              //set previous to first node
              previous = current;
              //set current to the next one
              current = current.next
          }
          //skip to the next node
          previous.next = current.next;
      }
      return current.value;
   };

   var Node = function(value){
      this.value = value;
      var next = {};
   };

   return that;
};


var linkedList = new LinkedList();
linkedList.push(1);
linkedList.push(2);
linkedList.push(3);
linkedList.push(4);

linkedList.remove(0);

console.log(linkedList.pop());
console.log(linkedList.pop());
console.log(linkedList.pop());
