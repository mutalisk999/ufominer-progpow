//
// Created by UFO Team
// Testcase from
// https://github.com/ifdefelse/ProgPOW/blob/master/test-vectors.md#progPowHash
//

#include <iostream>
#include <ethash/progpow.hpp>
#include <libdevcore/CommonData.h>

#define ETHASH_EPOCH_LENGTH 30000

int main(int argc, char** argv)
{
    {
        uint32_t block_num = 30000;
        std::string header_str = "ffeeddccbbaa9988776655443322110000112233445566778899aabbccddeeff";
        uint64_t nonce = 0x123456789abcdef0;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(
            dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

   {
        uint32_t block_num = 0;
        std::string header_str = "0000000000000000000000000000000000000000000000000000000000000000";
        uint64_t nonce = 0x0000000000000000;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

   {
        uint32_t block_num = 49;
        std::string header_str = "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b";
        uint64_t nonce = 0x0000000006ff2c47;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

   {
        uint32_t block_num = 50;
        std::string header_str = "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922";
        uint64_t nonce = 0x00000000076e482e;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

   {
        uint32_t block_num = 99;
        std::string header_str = "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d";
        uint64_t nonce = 0x000000003917afab;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

   {
        uint32_t block_num = 29950;
        std::string header_str = "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce";
        uint64_t nonce = 0x005d409dbc23a62a;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 29999;
        std::string header_str = "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5";
        uint64_t nonce = 0x005db5fa4c2a3d03;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 30000;
        std::string header_str = "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454";
        uint64_t nonce = 0x005db8607994ff30;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 30049;
        std::string header_str = "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64";
        uint64_t nonce = 0x005e2e215a8ca2e7;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 30050;
        std::string header_str = "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047";
        uint64_t nonce = 0x005e30899481055e;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 30099;
        std::string header_str = "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71";
        uint64_t nonce = 0x005ea6aef136f88b;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 59950;
        std::string header_str = "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6";
        uint64_t nonce = 0x02ebe0503bd7b1da;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 59999;
        std::string header_str = "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf";
        uint64_t nonce = 0x02edb6275bd221e3;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 10000000;
        std::string header_str = "efda178de857b2b1703d8d5403bd0f848e19cff5c50ba5c0d6210ddb16250ec3";
        uint64_t nonce = 0x005e30899481055e;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    {
        uint32_t block_num = 100000000;
        std::string header_str = "49e15ba4bf501ce8fe88765403bd0f848e19cff5c50ba5c0d6210ddb16250ec3";
        uint64_t nonce = 0x02abe0589481055e;

        const auto& context = progpow::get_global_epoch_context_full(block_num / ETHASH_EPOCH_LENGTH);
        auto header = progpow::hash256_from_bytes(dev::fromHex(header_str).data());

        auto result = progpow::hash(context, block_num, header, nonce);

        std::cout << "result: " << dev::toHex(result.final_hash.bytes) << "\n";
        // std::cout << "mix: " << dev::toHex(result.mix_hash.bytes) << "\n";
    }

    return 0;
}
