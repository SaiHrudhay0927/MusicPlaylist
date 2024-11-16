 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
typedef struct Song {
char *filename;
struct Song *next;
}Song;
Song *head = NULL;
void addSong(const char *filename) {
Song *newSong = (Song *)malloc(sizeof(Song));
newSong->filename = strdup(filename);
newSong->next = head;
if (head == NULL) {
head = newSong;
newSong->next = newSong;
} else {
Song *temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newSong;
newSong->next = head;
}
}
void playSong(Song *song) {
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
return;
}
Mix_Music *music = Mix_LoadMUS(song->filename);
if (music == NULL) {
printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
return;
}
Mix_PlayMusic(music, -1); // -1 means loop indefinitely
printf("Playing: %s\n", song->filename);
}
void displayPlaylist() {
if (head == NULL) {
printf("Playlist is empty.\n");
return;
}
Song *temp = head;
int index = 0;
do {
printf("%d: %s\n", index++, temp->filename);
temp = temp->next;
} while (temp != head);
}
int main(int argc, char *argv[]) {
SDL_Init(SDL_INIT_AUDIO);
addSong("/home/kali/Downloads/Song1.mp3");
addSong("/home/kali/Downloads/Song2.mp3");
addSong("/home/kali/Downloads/Song3.mp3");
displayPlaylist();
int choice;
Song *currentSong = head;
while (1) {
printf("\n--- Music Player ---\n");
printf("1. Play Current Song\n");
printf("2. Next Song\n");
printf("3. Pause Music\n");
printf("4. Resume Music\n");
printf("5. Stop Music\n");
printf("6. Exit\n");
printf("Choose an option: ");
scanf("%d", &choice);
switch (choice) {
case 1:
playSong(currentSong);
break;
case 2:
currentSong = currentSong->next;
playSong(currentSong);
printf("Next song: %s\n", currentSong->filename);
break;
case 3:
Mix_PauseMusic();
printf("Music paused.\n");
break;
case 4:
Mix_ResumeMusic();
printf("Music resumed.\n");
break;
case 5:
Mix_HaltMusic();
printf("Music stopped.\n");
break;
case 6:
printf("Exiting music player.\n");
Mix_HaltMusic(); // Ensure music is stopped before exiting
SDL_Quit();
return 0;
default:
printf("Invalid option. Please choose again.\n");
}
}
SDL_Quit();
return 0;
}
