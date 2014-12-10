#include <QTextStream>
QString DiffUtils::makePatch(const QList<FileData> &fileDataList, unsigned formatFlags)
    QTextStream str(&diffText);
        if (formatFlags & GitFormat) {
            str << "diff --git a/" << fileData.leftFileInfo.fileName
                << " b/" << fileData.rightFileInfo.fileName << '\n';
        }
            str << "Binary files ";
            if (formatFlags & AddLevel)
                str << "a/";
            str << fileData.leftFileInfo.fileName << " and ";
            if (formatFlags & AddLevel)
                str << "b/";
            str << fileData.rightFileInfo.fileName << " differ\n";
            str << "--- ";
            if (formatFlags & AddLevel)
                str << "a/";
            str << fileData.leftFileInfo.fileName << "\n+++ ";
            if (formatFlags & AddLevel)
                str << "b/";
            str << fileData.rightFileInfo.fileName << '\n';
                str << makePatch(fileData.chunks.at(j),
        if (line.isEmpty()) { // need to have at least one character (1 column)
            if (lastChunk)
                i = lines.count(); // pretend as we've read all the lines (we just ignore the rest)
            break;
        }
            if (firstCharacter == QLatin1Char(' ')) { // common line
            } else if (firstCharacter == QLatin1Char('-')) { // deleted line
            } else if (firstCharacter == QLatin1Char('+')) { // inserted line
            } else { // no other character may exist as the first character
                if (lastChunk)
                    i = lines.count(); // pretend as we've read all the lines (we just ignore the rest)
                break;
            }
    Differ::diffBetweenEqualities(leftDiffList,
                                  rightDiffList,
                                  &outputLeftDiffList,
                                  &outputRightDiffList);
    }
    const QRegExp leftFileRegExp(QLatin1String("^-{3} ")                 // "--- "
                                 + leftFileName                          // "a/fileName" or "/dev/null"
                                 + QLatin1String("(?:\\t[^\\n]*)*\\n")); // optionally followed by: \t anything \t anything ...)
    const QRegExp rightFileRegExp(QLatin1String("^\\+{3} ")               // "+++ "
                                  + rightFileName                         // "b/fileName" or "/dev/null"
                                  + QLatin1String("(?:\\t[^\\n]*)*\\n")); // optionally followed by: \t anything \t anything ...)
    const QRegExp binaryRegExp(QLatin1String("^Binary files ")
                               + leftFileName
                               + QLatin1String(" and ")
                               + rightFileName
                               + QLatin1String(" differ$"));

    // empty or followed either by leftFileRegExp or by binaryRegExp
    if (patch.isEmpty() && (fileData.fileOperation == FileData::NewFile
                         || fileData.fileOperation == FileData::DeleteFile)) {
        readOk = true;
    } else if (leftFileRegExp.indexIn(patch) == 0) {
        patch.remove(0, leftFileRegExp.matchedLength());
        // followed by rightFileRegExp
        if (rightFileRegExp.indexIn(patch) == 0) {
            patch.remove(0, rightFileRegExp.matchedLength());
            fileData.chunks = readChunks(patch,
                                         &fileData.lastChunkAtTheEndOfFile,
                                         &readOk);
    } else if (binaryRegExp.indexIn(patch) == 0) {
        readOk = true;
        fileData.binaryFiles = true;
static QList<FileData> readGitPatch(const QString &patch, bool *ok)
QList<FileData> DiffUtils::readPatch(const QString &patch, bool *ok)
    fileDataList = readGitPatch(croppedPatch, &readOk);
        fileDataList = readDiffPatch(croppedPatch, &readOk);