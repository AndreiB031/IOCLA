
void print_sensor(sensor *Sensor)
{
    if (Sensor == NULL)
    {
        printf("Index not in range!\n");
        return;
    }
    if (Sensor->sensor_type == TIRE)
    {
        printf("Tire Sensor\n");
        printf("Pressure: %.2f\n", ((tire_sensor *)(Sensor->sensor_data))->pressure);
        printf("Temperature: %.2f\n", ((tire_sensor *)(Sensor->sensor_data))->temperature);
        printf("Wear Level: %d%%\n", ((tire_sensor *)(Sensor->sensor_data))->wear_level);
        if (((tire_sensor *)(Sensor->sensor_data))->performace_score)
        {
            printf("Performance Score: %d\n", ((tire_sensor *)(Sensor->sensor_data))->performace_score);
        }
        else
        {
            printf("Performance Score: Not Calculated\n");
        }
        return;
    }
    if (Sensor->sensor_type == PMU)
    {
        printf("Power Management Unit\n");
        printf("Voltage: %.2f\n", ((power_management_unit *)(Sensor->sensor_data))->voltage);
        printf("Current: %.2f\n", ((power_management_unit *)(Sensor->sensor_data))->current);
        printf("Power Consumption: %.2f\n", ((power_management_unit *)(Sensor->sensor_data))->power_consumption);
        printf("Energy Regen: %d%%\n", ((power_management_unit *)(Sensor->sensor_data))->energy_regen);
        printf("Energy Storage: %d%%\n", ((power_management_unit *)(Sensor->sensor_data))->energy_storage);
        return;
    }
}