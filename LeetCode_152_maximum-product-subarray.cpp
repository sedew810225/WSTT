lass Solution {
public:
    int * ProdArray;
    
public:
    int maxProduct_trivial(vector<int>& nums) {        
        int subArrayCnt,i;
        int maxValue=0;
        ProdArray = new int[nums.size()+1];

        if (nums.size()==1) return nums[0];
    
                
        for (i=0;i<nums.size();i++){
            ProdArray[i] = nums[i];
            maxValue = max( maxValue , nums[i] );
        }
        
        for (subArrayCnt=1;subArrayCnt<nums.size();subArrayCnt++){
            for (i=0;i+subArrayCnt<nums.size();i++){
                ProdArray[i] = ProdArray[i] * nums[i+subArrayCnt];
                maxValue = max( maxValue , ProdArray[i] );
            }
        }     
        
        return maxValue;
    }
	
    int maxProduct(vector<int>& nums) {        
        int i;
        int maxValue=0;
        int curProd=1;
        int minusProd=1;

        maxValue = nums[0];
        
        for (i=0;i<nums.size();i++){
            
            if (nums[i] == 0 ) {
                minusProd = 1;
                curProd = 1;
                if ( maxValue < 0 ) maxValue = 0;
            } else {

                if ( curProd == 1 ) curProd = nums[i];
                else curProd *= nums[i];
                
                maxValue = max ( maxValue, curProd); 
                
                if (minusProd<0) {
                        minusProd *= nums[i];
                        maxValue = max ( maxValue, minusProd);
                }
                
                if (nums[i]<0) { 
                    swap ( minusProd , curProd );
                } 
            }
        }

        return maxValue;
    }
};