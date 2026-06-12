#include <stdio.h>
#include "heap.h"

int main() {
    printf("⚙️  Activating Factory PredictiveHeap-Queue System Interface...\n\n");

    PriorityMinHeap* dispatch_scheduler = allocate_heap(5);

    // Simulated degradation metrics calculated by edge model pipelines [Device ID, Current Health Score]
    MachineTask assembly_conveyor = {4001, 88.4};
    MachineTask hydraulic_press  = {4002, 14.2}; // Most critical failure risk profile input configuration
    MachineTask cooling_fan      = {4003, 65.9};

    queue_maintenance_task(dispatch_scheduler, assembly_conveyor);
    queue_maintenance_task(dispatch_scheduler, hydraulic_press);
    queue_maintenance_task(dispatch_scheduler, cooling_fan);

    printf("📥 Enqueued Systems Telemetry Analytics: ID 4001 (H=88.4), ID 4002 (H=14.2), ID 4003 (H=65.9)\n");

    MachineTask alert_dispatch = dispatch_highest_urgency_task(dispatch_scheduler);
    printf("\n🚨 Urgent Maintenance Event Dispatched:\n");
    printf("   👉 Target Machine Hardware ID Identifier Reference: %d\n", alert_dispatch.hardware_id);
    printf("   👉 Evaluated Component Residual Structural Health Metric: %.1f%%\n", alert_dispatch.structural_health_score);

    clear_heap_framework(dispatch_scheduler);
    return 0;
}
