#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	const char *face;
	const char *suit;
};


typedef struct card Card;

void filldeck(Card * const wDeck, const char * wFace[],
	const char * wsuit[]);

void shuffle(Card * const wDeck);
void deal(const Card * const Wdeck);


int main(void) {
	Card deck[52];

	const char *face[] = { "Ace","Deuce","Three","Four","Five",
		"Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

	const char *suit[] = { "Hearts","Diamonds","Cubes","Spades" };

	srand(time(NULL));

	filldeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	system("pause");
	return 0;


}

void filldeck(Card * const wDeck, const char * wFace[],
	const char * wSuit[])
{
	int i;

	for (i = 0; i <= 51; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}

}

void shuffle(Card * const wDeck)
{
	int i, j;
	Card temp;

	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card * const Wdeck)
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", Wdeck[i].face, Wdeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}

}