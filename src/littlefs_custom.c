#include "esp_log.h"
#include "esp_partition.h"
#include "esp_vfs.h"
#include "littlefs/lfs.h"
#include "esp_littlefs.h"
#include "littlefs_api.h"

int littlefs_custom_read(const struct lfs_config *c, lfs_block_t block,
                         lfs_off_t off, void *buffer, lfs_size_t size)
{
    esp_littlefs_t *efs = c->context;
    void *user_context = efs->custom.context;
    return efs->custom.read(user_context, block, off, buffer, size);
}

int littlefs_custom_write(const struct lfs_config *c, lfs_block_t block,
                          lfs_off_t off, const void *buffer, lfs_size_t size)
{
    esp_littlefs_t *efs = c->context;
    void *user_context = efs->custom.context;
    return efs->custom.write(user_context, block, off, buffer, size);
}

int littlefs_custom_erase(const struct lfs_config *c, lfs_block_t block)
{
    esp_littlefs_t *efs = c->context;
    void *user_context = efs->custom.context;
    return efs->custom.erase(user_context, block);
}

int littlefs_custom_sync(const struct lfs_config *c)
{
    esp_littlefs_t *efs = c->context;
    void *user_context = efs->custom.context;
    return efs->custom.sync(user_context);
}
