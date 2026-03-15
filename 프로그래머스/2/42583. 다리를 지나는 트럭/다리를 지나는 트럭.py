def solution(bridge_length, weight, truck_weights):
    num_truck = len(truck_weights)
    truck_dist = [bridge_length] * num_truck
    
    start = 0 # first truck on the bridge
    end = 1 # last truck 
    sum_weight = truck_weights[start]
    time = 1
    while start < num_truck :

        time += 1
        for i in range(start, end) :
            truck_dist[i] -= 1

        if truck_dist[start] == 0 :
            sum_weight -= truck_weights[start]
            start += 1
            
        if  end < num_truck and sum_weight + truck_weights[end] <= weight :
            sum_weight += truck_weights[end]
            end += 1
        

            
    return time

        