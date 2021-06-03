CC = g++
H = BigInt.h
CA = asn1_a.cpp BigInt.cpp
CB = asn1_b.cpp BigInt.cpp
CPPC = asn1_c.cpp BigInt.cpp
EXECA = asn1_a
EXECB = asn1_b
EXECC = asn1_c

build: ${H}
	${CC} -std=c++11 ${CA} -o ${EXECA}
	${CC} -std=c++11 ${CB} -o ${EXECB}
	${CC} -std=c++11 ${CPPC} -o ${EXECC}

clean:
	@echo "Cleaning up..."
	rm -v -f ${EXECA} ${EXECB} ${EXECC} *.o

asn1_a:
	${CC} -std=c++11 ${CA} -o ${EXECA}

asn1_b:
	${CC} -std=c++11 ${CB} -o ${EXECB}

asn1_c:
	${CC} -std=c++11 ${CPPC} -o ${EXECC}

testA:
	time ./${EXECA}

testB:
	time ./${EXECB}

testB_flex:
	time ./${EXECB} 100000 20000

testC:
	time ./${EXECC}

runA:
	make clean
	make
	make testA

runB:
	make clean
	make
	make testB

runB_flex:
	make clean
	make
	make testB_flex

runC:
	make clean
	make
	make testC
