TARGET = main

CFLAGS = -g -O2 -Wall -pedantic
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`


all: $(TARGET)

$(TARGET):
	gcc $(CFLAGS) main.c joue_graph.c graphique.c ascii.c token.c sauvegarde.c -o projet $(LDLIBS)


clean:
	-rm -rf	$(TARGET)

