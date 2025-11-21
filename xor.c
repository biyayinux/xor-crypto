#include <stdio.h>
#include <string.h>

void xor_encrypt(const char *input, const char *key, char *output) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];  // XOR avec répétition de la clé
    }
    output[input_len] = '\0'; // Fin de chaîne
}

int main() {
    char message[] = "Bonjour";
    char key[] = "KEY";

    char encrypted[256];
    char decrypted[256];

    // Chiffrement
    xor_encrypt(message, key, encrypted);
    printf("Texte chiffré (en bytes) : ");
    for(int i = 0; i < strlen(message); i++) {
        printf("%02X ", (unsigned char)encrypted[i]);
    }
    printf("\n");

    // Déchiffrement (on XOR à nouveau avec la même clé)
    xor_encrypt(encrypted, key, decrypted);
    printf("Texte déchiffré : %s\n", decrypted);

    return 0;
}
