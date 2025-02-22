#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Çift yönlü bağlı liste düğüm yapısı
typedef struct LogNode {
    char log_entry[MAX_LINE_LENGTH];
    struct LogNode* prev;
    struct LogNode* next;
} LogNode;

// Bağlı listeye yeni bir düğüm ekleyen fonksiyon
void append_log(LogNode** head, const char* log_entry) {
    if (strstr(log_entry, "ERROR") == NULL) {
        return; // Sadece ERROR içeren logları ekle
    }
    
    LogNode* new_node = (LogNode*)malloc(sizeof(LogNode));
    if (!new_node) {
        perror("Memory allocation failed");
        return;
    }
    strncpy(new_node->log_entry, log_entry, MAX_LINE_LENGTH);
    new_node->log_entry[MAX_LINE_LENGTH - 1] = '\0';
    new_node->next = NULL;
    
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
    } else {
        LogNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Bağlı listedeki logları ekrana yazdıran fonksiyon
void print_logs(LogNode* head) {
    LogNode* temp = head;
    while (temp != NULL) {
        printf("%s", temp->log_entry);
        temp = temp->next;
    }
}

// Belleği temizleme fonksiyonu
void free_logs(LogNode* head) {
    LogNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* file = fopen("/var/log/syslog", "r");
    if (!file) {
        perror("Could not open syslog file");
        return 1;
    }

    LogNode* log_list = NULL;
    char line[MAX_LINE_LENGTH];
    
    // Syslog dosyasını satır satır oku ve ERROR içerenleri listeye ekle
    while (fgets(line, sizeof(line), file)) {
        append_log(&log_list, line);
    }

    fclose(file);

    // ERROR içeren logları ekrana yazdır
    print_logs(log_list);

    // Belleği temizle
    free_logs(log_list);
    
    return 0;
}
