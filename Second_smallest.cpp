int getSecondSmallest(vector<int>& arr){
int smallest = INT_MAX, second_smallest = INT_MAX;

  for(int num: arr){
    if(num < smallest){
      second_smallest = smallest;
      smallest = num;
    } else if(num < second_smallest && num != smallest){
      second_smallest = num;
    }
  }
  return second_smallest;
}
