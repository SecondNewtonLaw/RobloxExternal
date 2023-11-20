//
// Created by Dottik on 19/11/2023.
//

#pragma once

#include <optional>
#include <oxorany.hpp>
#include "Roblox.hpp"

// INSTANCE_OFFSETS
#define NAME_OFFSET (oxorany(0x48))
#define CHILDREN_OFFSET (oxorany(0x50))
#define PARENT_OFFSET (oxorany(0x60))

class RobloxInstance {
public:
    RobloxInstance() {
        this->m_pRune = nullptr;
        this->m_rpInstance = 0x0;
        this->m_bInitialised = false;
    }

    RobloxInstance(Roblox *rune, uintptr_t instanceAddress) {
        this->m_pRune = rune;
        this->m_rpInstance = instanceAddress;
        this->m_bInitialised = true;
    };

    void Initialize(Roblox *rune, uintptr_t instanceAddress) {
        this->m_pRune = rune;
        this->m_rpInstance = instanceAddress;
        this->m_bInitialised = true;
    }

    std::vector<RobloxInstance> GetChildren();

    RobloxInstance GetParent();

    [[nodiscard]] std::uintptr_t GetAddress() const;

    std::optional<RobloxInstance> FindFirstChild(const char *szInstanceName);

    const char *GetName();

    const char *GetInstanceClassName();

private:

    bool m_bInitialised;
    Roblox *m_pRune{};
    std::uintptr_t m_rpInstance{};

    DWORD64 CalculateNameOffset();

    DWORD64 CalculateChildrenOffset();
};


