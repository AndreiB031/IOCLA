#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "functions.h"

int main(int argc, char const *argv[]){
	argc = 2;
	argv[1] = "/home/student/Desktop/Tema/tema-1/checker/input/sensors_analyse_1.dat";
	int file_number = 0;
	for (file_number = 1; file_number < argc; file_number++) {
		FILE *file_in = fopen(argv[file_number], "rb");
		if (!file_in) {

    printf("Error opening file1\n");
    return 1;

}
		int sensor_nmb = 0;
		fread(&sensor_nmb, sizeof(int), 1, file_in);
		sensor** Sensor = malloc(sensor_nmb* sizeof(sensor*));
		int i = 0;
		int sensor_type = 0;
		for (i = 0; i < sensor_nmb; i++) {
			Sensor[i] = malloc(sizeof(sensor));
			fread(&sensor_type, sizeof(int), 1, file_in);
			if (sensor_type == 0) {
				Sensor[i]->sensor_type = TIRE;
				Sensor[i]->sensor_data = malloc(sizeof(tire_sensor));
				fread(&(((tire_sensor*)(Sensor[i]->sensor_data))->pressure), sizeof(float), 1, file_in);
				fread(&(((tire_sensor*)(Sensor[i]->sensor_data))->temperature), sizeof(float), 1, file_in);
				fread(&(((tire_sensor*)(Sensor[i]->sensor_data))->wear_level), sizeof(int), 1, file_in);
				fread(&(((tire_sensor*)(Sensor[i]->sensor_data))->performace_score), sizeof(int), 1, file_in);
				fread(&(Sensor[i]->nr_operations), sizeof(int), 1, file_in);
				Sensor[i]->operations_idxs = malloc((Sensor[i]->nr_operations) * sizeof(int));
				fread(Sensor[i]->operations_idxs, sizeof(int), Sensor[i]->nr_operations, file_in);
			}
			if (sensor_type == 1) {
				Sensor[i]->sensor_type = PMU;
				Sensor[i]->sensor_data = malloc(sizeof(power_management_unit));
				fread(&(((power_management_unit*)(Sensor[i]->sensor_data))->voltage), sizeof(float), 1, file_in);
				fread(&(((power_management_unit*)(Sensor[i]->sensor_data))->current), sizeof(float), 1, file_in);
				fread(&(((power_management_unit*)(Sensor[i]->sensor_data))->power_consumption), sizeof(float), 1, file_in);
				fread(&(((power_management_unit*)(Sensor[i]->sensor_data))->energy_regen), sizeof(int), 1, file_in);
				fread(&(((power_management_unit*)(Sensor[i]->sensor_data))->energy_storage), sizeof(int), 1, file_in);
				fread(&(Sensor[i]->nr_operations), sizeof(int), 1, file_in);
				Sensor[i]->operations_idxs = malloc(Sensor[i]->nr_operations * sizeof(int));
				fread(Sensor[i]->operations_idxs, sizeof(int), Sensor[i]->nr_operations, file_in);
			}

		}
		char s[10];
		while(7) {
			scanf("%s", s);
			if (!strcmp(s, "print")) {
				int number = 0;
				scanf("%d", &number);
				print_sensor(Sensor[number]);
			}
			if (!strcmp(s, "exit")) {
				break;
			}
		}
	}
	return 0;
}
