#include <libdevcore/CommonData.h>
#include <ethash/progpow.hpp>
#include <iostream>
#include <string>
#include "openssl/sha.h"


#define ETHASH_EPOCH_LENGTH 30000

int main(int argc, char** argv)
{
    // header: c07acfc3fa2e92ac9ff331bb04743f7851e9d7a99e05ec7589d4b05d1505ae56
    // result: 49c1c439e996cb656d69b51556e949e99e88a1e850dd01ebbd29b8f1328474b8
    // mixhash: b72f1079a42a23f89b4820747a10fd79c843262562512fb5f95900135ce8bfd5
    {
        unsigned char out[32];
        unsigned char* p = out;

        std::string prev = "debc2337f1cac3b17af2eb4896ecf471eb9a3a5c2aa8a3f3f51a000000000000";
        std::string input = "3cb122e3db784a1da40ba5c1fe1a6fc4d2eabad1b43b6114de08a37b00aa2e5c";
        uint64_t nonce = 0x123456789abcdef0;
        int block = 54321;

        std::string hash_str_no_nonce = "00000000" + prev + "00000000" + input;

        SHA256((const unsigned char*)hash_str_no_nonce.c_str(), hash_str_no_nonce.length(), p);

        // calc header
        std::string header = dev::toHex(out);
        std::cout << "header:" << header << std::endl;

        const progpow::epoch_context_full& context = progpow::get_global_epoch_context_full(block / ETHASH_EPOCH_LENGTH);
        auto header_hash = progpow::hash256_from_bytes(out);

        progpow::result r = progpow::hash(context, block, header_hash, nonce);

        std::string res = dev::toHex(r.final_hash.bytes);
        std::string mix = dev::toHex(r.mix_hash.bytes);

        std::cout << "result:" << res << std::endl;
        std::cout << "mixhash:" << mix << std::endl;
    }

    // header:d1bfac57e2c35c12d8d8e0f5359dc4c9bee99e766e3be6a4440e3daa64b7fc7a
    // result:0000003a58b8b23f9ee76ac3c6610c1eedf54a9bfe4d4a4244ea6760e4773cda
    // mixhash:93c8b0e96fd32c30b7e2973675732d23778a70d56b3ff10a9d864bceae0d8e3a
    {
        unsigned char out[32];
        unsigned char* p = out;

        std::string prev = "0260a6691258391335617a8c0f7c95fe0e927b081cba168e6454c784a9000000";
        std::string input = "4f17a79c23db4e607c64b57d20bf7f01624eb6e55b4713cbc88011bcbc94ab22";
        uint64_t nonce = std::stoull(std::string("0000") + std::string("000003fe80e8"), NULL, 16);
        int block = 30;

        std::string hash_str_no_nonce = "00000000" + prev + "00000000" + input;

        SHA256((const unsigned char*)hash_str_no_nonce.c_str(), hash_str_no_nonce.length(), p);

        // calc header
        std::string header = dev::toHex(out);
        std::cout << "header:" << header << std::endl;

        const progpow::epoch_context_full& context =
            progpow::get_global_epoch_context_full(block / ETHASH_EPOCH_LENGTH);
        auto header_hash = progpow::hash256_from_bytes(out);

        progpow::result r = progpow::hash(context, block, header_hash, nonce);

        std::string res = dev::toHex(r.final_hash.bytes);
        std::string mix = dev::toHex(r.mix_hash.bytes);

        std::cout << "result:" << res << std::endl;
        std::cout << "mixhash:" << mix << std::endl;
    }

    return 0;
}
