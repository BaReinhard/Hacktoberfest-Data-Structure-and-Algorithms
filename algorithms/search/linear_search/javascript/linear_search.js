var linearSearch = function(list, target){
  var result = null,
      i = 0, value;
  for(; i < list.length; i++){
    value = list[i];
    if(value === target){
      result = i;
      break;
    }
  }
  return result;
};
