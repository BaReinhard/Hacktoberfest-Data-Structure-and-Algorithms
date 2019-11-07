Array.prototype.mergeSort = function(){
    if(this.length > 1){
      const mid = this.length/2;
      let leftArray = this.slice(0, mid);
      let rightArray = this.slice(mid);
  
      leftArray.mergeSort();
      rightArray.mergeSort();
  
      let i = 0, j = 0, k = 0;
  
      while(i < leftArray.length && j < rightArray.length){
        if(leftArray[i] < rightArray[j]){
          this[k] = leftArray[i];
          i++;
        } else {
          this[k] = rightArray[j];
          j++;
        }
        k++;
      }
  
      while(i < leftArray.length){
        this[k] = leftArray[i];
        i++;
        k++;
      }
  
      while(j < rightArray.length){
        this[k] = rightArray[j];
        j++;
        k++;
      }
    }
  };
