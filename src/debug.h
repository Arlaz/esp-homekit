#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdlib.h>
#include <stdio.h>

#ifdef ESP_IDF
#include <esp_log.h>
static const char* HK_TAG = "HomeKit";
#endif

typedef unsigned char byte;

#ifdef HOMEKIT_DEBUG
#ifdef ESP_IDF
#define DEBUG(message, ...) ESP_LOGD(HK_TAG, "func %s: " message, __func__, ##__VA_ARGS__)
#else
#define DEBUG(message, ...) printf(">>> %s: " message "\n", __func__, ##__VA_ARGS__)
#endif
#else

#define DEBUG(message, ...)

#endif


#ifdef ESP_IDF
#define INFO(message, ...) ESP_LOGI(HK_TAG, message, ##__VA_ARGS__)
#define ERROR(message, ...) ESP_LOGE(HK_TAG, message, ##__VA_ARGS__)
#define DEBUG_HEAP() DEBUG("Free heap: %d", esp_get_free_heap_size());

#else
#define INFO(message, ...) printf(">>> HomeKit: " message "\n", ##__VA_ARGS__)
#define ERROR(message, ...) printf("!!! HomeKit: " message "\n", ##__VA_ARGS__)
#define DEBUG_HEAP() DEBUG("Free heap: %d", xPortGetFreeHeapSize());
#endif

char *binary_to_string(const byte *data, size_t size);
char *binary_to_stringv(uint8_t n, const byte **datas, size_t *sizes);
void print_binary(const char *prompt, const byte *data, size_t size);

#endif // __DEBUG_H__
