#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int hardware_id;
    double structural_health_score; // Health Index: 0.0 (Catastrophic Fault) to 100.0 (Perfect Nominal)
} MachineTask;

typedef struct {
    MachineTask* array_pool;
    int system_size;
    int limit_capacity;
} PriorityMinHeap;

PriorityMinHeap* allocate_heap(int capacity);
void queue_maintenance_task(PriorityMinHeap* hp, MachineTask task);
MachineTask dispatch_highest_urgency_task(PriorityMinHeap* hp);
void clear_heap_framework(PriorityMinHeap* hp);

#endif
