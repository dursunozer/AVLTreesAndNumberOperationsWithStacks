all:derle bagla calistir

derle:
	@g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	@g++ -c -I "./include" ./src/AVLDugum.cpp -o ./lib/AVLDugum.o
	@g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	@g++ -c -I "./include" ./src/ListeDugum.cpp -o ./lib/ListeDugum.o
	@g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	@g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
	@g++ -c -I "./include" ./src/YiginDugum.cpp -o ./lib/YiginDugum.o
bagla:
	@g++ ./lib/AVLAgaci.o ./lib/AVLDugum.o ./lib/Liste.o ./lib/ListeDugum.o ./lib/main.o ./lib/Yigin.o ./lib/YiginDugum.o -o ./bin/program
calistir:
	./bin/program