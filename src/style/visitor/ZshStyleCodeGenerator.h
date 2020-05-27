#ifndef ZSHSTYLECODEGENERATOR_H
#define ZSHSTYLECODEGENERATOR_H

#include "style/BoldStyle.h"
#include "style/DoubleUnderlineStyle.h"
#include "style/FaintStyle.h"
#include "style/ItalicStyle.h"
#include "style/ResetStyle.h"
#include "style/StrikethroughStyle.h"
#include "style/UnderlineStyle.h"
#include "style/visitor/ANSIStyleCodeGenerator.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class ZshStyleCodeGenerator : public ANSIStyleCodeGenerator {
        public:
        ZshStyleCodeGenerator();
        virtual ~ZshStyleCodeGenerator();

        virtual string visit_start(BoldStyle& style) override;
        virtual string visit_end(BoldStyle& style) override;

        virtual string visit_start(FaintStyle& style) override;
        virtual string visit_end(FaintStyle& style) override;

        virtual string visit_start(ItalicStyle& style) override;
        virtual string visit_end(ItalicStyle& style) override;

        virtual string visit_start(UnderlineStyle& style) override;
        virtual string visit_end(UnderlineStyle& style) override;

        virtual string visit_start(DoubleUnderlineStyle& style) override;
        virtual string visit_end(DoubleUnderlineStyle& style) override;

        virtual string visit_start(StrikethroughStyle& style) override;
        virtual string visit_end(StrikethroughStyle& style) override;

        virtual string visit_start(ResetStyle& style) override;
        virtual string visit_end(ResetStyle& style) override;
    };
} // namespace velocity::style

#endif // ZSHSTYLECODEGENERATOR_H
