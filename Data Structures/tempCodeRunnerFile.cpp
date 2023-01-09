vector<int> JobScheduling(Job arr[], int n) 
    // { 
    //     sort(arr, arr+n, [] (Job a, Job b) {return a.profit>b.profit;});
    //     vector<int> greedy(n,0);
        
    //     for(int i=0; i<n; i++){
    //         for(int j = arr[i].dead-1; j>=0; j--){
    //             if(greedy[j] == 0){
    //                 greedy[j] = arr[i].profit;
    //                 break;
    //             }
    //         }
    //     }  
    //     int count=0 , ans=0;
    //     for(int i=0; i<n; i++){
    //         if(greedy[i]!=0){
    //             count++;
    //             ans+=greedy[i];
    //         }
    //     } 
    //     return {count,ans};
    // } 