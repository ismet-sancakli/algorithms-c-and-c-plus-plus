#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

const int widht = 1500;
const int height = 800;

int main()
{
	srand(time(NULL));
	const float FPS = 60.0;

	ALLEGRO_DISPLAY *display = NULL; // Burada extradan bir oyun penceresi oluþturduk.Büyük harfle olan komutlar bir þeyler oluþturmamýz için.	 
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_TIMER *timer;

	al_init(); // Allegronun baþlamasý için gerekli olan komut.

	al_init_primitives_addon(); // Burada ayrýca kullanmak için onay verdiðimiz addonlarý baþlatýyoruz.
	al_install_mouse();			// Mouse kullanmak için.
	al_init_font_addon();

	display = al_create_display(widht, height);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	
	int pos_x = widht / 2, pos_y = height / 2, moveSpeed = 5;


}