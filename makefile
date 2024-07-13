carBase: main.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o
	gcc -Wall -std=c99 main.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o -o bin/carBase

main.o: src/main.c include/header.h
	gcc -Wall -std=c99 -c src/main.c -Iinclude

addNewCar.o: src/addNewCar.c include/header.h
	gcc -Wall -std=c99 -c src/addNewCar.c -Iinclude

loadCarData.o: src/loadCarData.c include/header.h
	gcc -Wall -std=c99 -c src/loadCarData.c -Iinclude

printAll.o: src/printAll.c include/header.h
	gcc -Wall -std=c99 -c src/printAll.c -Iinclude

printOne.o: src/printOne.c include/header.h
	gcc -Wall -std=c99 -c src/printOne.c -Iinclude

lookForCarId.o: src/lookForCarId.c include/header.h
	gcc -Wall -std=c99 -c src/lookForCarId.c -Iinclude

lookForCarModelType.o: src/lookForCarModelType.c include/header.h
	gcc -Wall -std=c99 -c src/lookForCarModelType.c -Iinclude

countCars.o: src/countCars.c include/header.h
	gcc -Wall -std=c99 -c src/countCars.c -Iinclude

sortCarId.o: src/sortCarId.c include/header.h
	gcc -Wall -std=c99 -c src/sortCarId.c -Iinclude

oneLessCar.o: src/oneLessCar.c include/header.h
	gcc -Wall -std=c99 -c src/oneLessCar.c -Iinclude

noMoreCars.o: src/noMoreCars.c include/header.h
	gcc -Wall -std=c99 -c src/noMoreCars.c -Iinclude

clean:
	rm -r *.o bin/carBase
