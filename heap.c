#include <stdlib.h>
#include "heap.h"

PriorityMinHeap* allocate_heap(int capacity) {
    PriorityMinHeap* hp = (PriorityMinHeap*)malloc(sizeof(PriorityMinHeap));
    hp->system_size = 0;
    hp->limit_capacity = capacity;
    hp->array_pool = (MachineTask*)malloc(capacity * sizeof(MachineTask));
    return hp;
}

void internal_node_swap(MachineTask* x, MachineTask* y) {
    MachineTask temporary = *x; *x = *y; *y = temporary;
}

void queue_maintenance_task(PriorityMinHeap* hp, MachineTask task) {
    if (hp->system_size >= hp->limit_capacity) return;
    
    hp->array_pool[hp->system_size] = task;
    int current_idx = hp->system_size;
    hp->system_size++;

    // Shift-Up restructuring sequence loop to maintain min-heap conditions
    while (current_idx != 0 && hp->array_pool[(current_idx - 1) / 2].structural_health_score > hp->array_pool[current_idx].structural_health_score) {
        internal_node_swap(&hp->array_pool[current_idx], &hp->array_pool[(current_idx - 1) / 2]);
        current_idx = (current_idx - 1) / 2;
    }
}

MachineTask dispatch_highest_urgency_task(PriorityMinHeap* hp) {
    if (hp->system_size <= 0) { MachineTask blank = {-1, 100.0}; return blank; }
    if (hp->system_size == 1) { hp->system_size--; return hp->array_pool[0]; }

    MachineTask target_critical_node = hp->array_pool[0];
    hp->array_pool[0] = hp->array_pool[hp->system_size - 1];
    hp->system_size--;

    // Shift-Down balancing execution logic
    int tracking_idx = 0;
    while ((2 * tracking_idx + 1) < hp->system_size) {
        int left_child_idx = 2 * tracking_idx + 1;
        int right_child_idx = 2 * tracking_idx + 2;
        int lowest_health_idx = left_child_idx;

        if (right_child_idx < hp->system_size && hp->array_pool[right_child_idx].structural_health_score < hp->array_pool[left_child_idx].structural_health_score) {
            lowest_health_idx = right_child_idx;
        }
        if (hp->array_pool[tracking_idx].structural_health_score <= hp->array_pool[lowest_health_idx].structural_health_score) {
            break;
        }
        internal_node_swap(&hp->array_pool[tracking_idx], &hp->array_pool[lowest_health_idx]);
        tracking_idx = lowest_health_idx;
    }
    return target_critical_node;
}

void clear_heap_framework(PriorityMinHeap* hp) {
    free(hp->array_pool); free(hp);
}
