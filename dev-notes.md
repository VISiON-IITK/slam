# Development

Prashant: As in our scenario there is almost no chance of loop clousre so the slam solution should focus on better trajectories which in turn will lead to better map. 

Prashant: Scan matching can be used for better odometry which leads to better trajectories. But for scan matching to work we need better local maps. So we should at first wait at the initial position to build a good local map and then move in it using scan matching and then wait and repeat...---More thought needed---

Prashant-Doubt: Our odometry reading is produced by controls or imu or both. If not both, then can we somehow integrate both?

!IMPORTANT TASK!: Learn Quaternion Math fast!!