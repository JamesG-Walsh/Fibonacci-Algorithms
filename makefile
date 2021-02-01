CC = g++
H = BigInt.h 
C = asn1.cpp BigInt.cpp
EXEC = asn1_a

build: ${C} ${H}
	${CC} ${C} -o ${EXEC}

test:
	./${EXEC}

clean:
	@echo "Cleaning up..."
	rm ${EXEC} *.o -v -f

run:
	make clean
	make
	make test