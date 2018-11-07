// ============================================================================
//                 SeqAn - The Library for Sequence Analysis
// ============================================================================
//
// Copyright (c) 2006-2018, Knut Reinert & Freie Universitaet Berlin
// Copyright (c) 2016-2018, Knut Reinert & MPI Molekulare Genetik
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Knut Reinert or the FU Berlin nor the names of
//       its contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL KNUT REINERT OR THE FU BERLIN BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ============================================================================

#include <type_traits>

#include <seqan3/alphabet/nucleotide/dna4.hpp>
#include <seqan3/range/container/bitcompressed_vector.hpp>
#include <seqan3/range/view/kmer_hash.hpp>

#include <gtest/gtest.h>

using namespace seqan3;
using namespace seqan3::literal;

TEST(kmer_hash, view)
{
    {
        std::vector<dna4> text{"AAAAA"_dna4};
        std::vector<size_t> hashes = text | view::kmer_hash(3);
        std::vector<size_t> expected{0,0,0};
        EXPECT_EQ(expected, hashes);
    }
    {
        std::vector<dna4> text{"ACGTAGC"_dna4};
        std::vector<size_t> hashes = text | view::kmer_hash(3);
        std::vector<size_t> expected{6,27,44,50,9};
        EXPECT_EQ(expected, hashes);
    }
    {
        std::vector<dna4> text{"AC"_dna4};
        std::vector<size_t> hashes = text | view::kmer_hash(3);
        std::vector<size_t> expected{};
        EXPECT_EQ(expected, hashes);
    }
    {
        bitcompressed_vector<dna4> text{"ACGTAGC"_dna4};
        std::vector<size_t> hashes = text | view::kmer_hash(3);
        std::vector<size_t> expected{6,27,44,50,9};
        EXPECT_EQ(expected, hashes);
    }
}
